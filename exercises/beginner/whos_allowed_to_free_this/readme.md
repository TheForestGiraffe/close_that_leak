# Beginner Exercise — “Who’s Allowed to Free This?”

**a helper frees or exits even though it doesn’t clearly own the resources**.

Your job: spot the problem and explain why it can be a problem.

---

## Questions

1. **Who owns `app.buffer`?**  
   Who should free it?

2. **Who owns `line`?**  
   Which function should decide when it gets freed?

3. What is surprising about `line_or_die()`?
   - What does its name suggest?
   - What does it *actually* do?

4. Why is it a problem that a helper calls `destroy_app()` and exits?
   - Think about: testing, reuse, and control flow.

---

## “Better” direction (hint)

A more common style is:

- Helpers return an error (`NULL` / `-1`)
- The **owner** decides how to clean up and whether to exit