# Copy

Because `cp` sucks.

## Behavior:

Run the command this way:

```bash
$ copy ../../source1/* ../source2 source3 to destination1/ destination2
```

The output will be like this:

```bash
copy_test_src/a to copy_test_dst/a 193376898/639631360 [#########################-------------------------------------------------------------]
```

Once it's done it will say:

```bash
copy_test_src/a to copy_test_dst/a 639631360/639631360 ok!
```

## Features

- Progress bar (Done).
- Files in directory to another directory (Done).
- Multiple sources (Done).
- Easy to read syntax (Done).

[License](http://sadasant.com/license)
