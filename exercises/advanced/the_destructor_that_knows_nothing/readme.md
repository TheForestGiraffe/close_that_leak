# Exercise 2 — “The Destructor That Knows Nothing”

### Task:  
Make the destructor always safe without adding extra state variables.

```c 
typedef struct s_item
{
    char **strs; // NULL-terminated array of strs
}   t_item;
```

```c
t_item *item_create(char **tokens)
{
    t_item *item;

    if (!tokens || !tokens[0] || !tokens[1])
        return (NULL);

    item = malloc(sizeof(*item));
    if (!item)
        return (NULL);

    item->strs = malloc(3 * sizeof(char *));
    if (!item->strs)
        return (item);

    item->strs[0] = strdup(tokens[0]);
    if (!item->strs[0])
        return (item); 

    item->strs[1] = strdup(tokens[1]);
    if (!item->strs[1])
        return (item);

    item->strs[2] = NULL;
    return (item);
}
```

Destructor:

```c
void item_destroy(t_item *item)
{
    int i = 0;
    while (item->strs[i])
        free(item->strs[i++]);
    free(item->strs);
}
```

“Your destructor is blindfolded. Make it safe.”