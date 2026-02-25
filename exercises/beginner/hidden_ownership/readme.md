# Beginner Exercise — Hidden Ownership (No realloc)

This is a *very small* program that demonstrates a common ownership smell:

> A helper function frees memory it did not clearly own.


---

## What to notice

### The helper has a surprising contract

`append_number(char *s, int n)`:

- sometimes **frees `s`**
- sometimes returns `NULL`
- the signature does **not** tell you that `s` might be freed

So from the caller’s point of view, this line is risky:

```c
msg = append_number(msg, 1);
```

If `append_number` frees `s` internally, the caller must **never** try to free the old pointer again.
But the caller also cannot easily know what happened on failure without reading the helper’s code.

---

## Questions

1. Who owns `msg` in `main` before calling `append_number`?
2. After calling `append_number`, who owns the returned pointer?
3. Is it OK that `append_number` frees `s`?
   - If yes: what MUST be documented / made explicit?
   - If no: what should change?
4. What is the worst-case bug this pattern can cause during refactoring?

---
