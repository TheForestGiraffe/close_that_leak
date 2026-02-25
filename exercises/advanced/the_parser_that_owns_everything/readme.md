# Exercise — “The Parser That Owns Everything (…by accident)”

This exercise is about **ownership, cleanup, and error handling boundaries** in C.

You are given an extract from an FdF project (map loading / parsing).  
The code “works” in the sense that it tries to clean up and exit on errors — but it also hides **ownership transfers** and performs **global cleanup from deep inside helper functions**.



---- Your job is to spot the pattern, explain why it can be a problem, and decide whether you agree with it. -----

There is no need to change the code. Just explain what's the problem in terms of ownership, how it could be different, and your opinion about it.



---

## Learning goals

By the end, you should be able to:

- Detect **hidden ownership transfer** (a function freeing something it didn’t clearly own).
- Detect **cleanup + exit** happening in a module that shouldn’t control program lifetime.
- Explain architectural consequences:
  - harder testing,
  - less reuse,
  - surprising side effects (?),
  - tighter coupling...

---

## The code you should focus on

Look at these files:

- `fdf.c` (caller)
- `load_map/load_map.c` (module entry point)
- `load_map/parse_map.c` (parser)
- `load_map/try_open.c` (try helper)
- `load_map/try_ft_split.c` (try helper)

You’ll notice a pattern: functions named `try_*` **do not return errors** — they do **local cleanup + exit**.

### Caller: `fdf.c`

```c
app.model = load_map(argv[1], &app);
```

Observation: `load_map()` receives `t_app *app` (the **whole application**) even though the loader is “just parsing a file”.

- The parser is able to shut down the whole program by calling `destroy_app()` indirectly.

(Yes: in this extract `model` isn’t set up — other parts are commented out. That’s not the exercise.)


Observation:
- `try_open()` is a low-level helper, but it:
  - prints an error,
  - destroys the entire app,
  - exits (likely inside `destroy_app`).


This means:
- The **parser module** controls **program lifetime**.
- Any caller using `load_map()` loses control over error handling.

---

## Do you agree with this design?

Discuss as a group:

### Reasons someone might like it
- Centralized fatal-exit behavior.
- Faster to write for small projects.

### Reasons it may be a problem
- **Hidden coupling**: parser now depends on the whole application (`t_app`).
- **Hard to test**: any failure path exits the process.
- **Hard to reuse**: you can’t use `load_map()` from another program/module easily.
- **Unclear ownership**: `try_ft_split` may free memory it didn’t “announce” ownership of.
- ...

Your conclusion can be:
- “I agree” (with conditions), or
- “I disagree”, or
- “It depends” — but justify it.