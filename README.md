# yambar-diskview
A Yambar module written in C for displaying disk usage. 

## Usage
```bash
Usage: ./yambar-diskview <interval_seconds> <path1> [path2 ... pathN]
```

## Example output
```
$ yambar-diskview 5 / "$HOME"
/_free|int|4291997696
/_avail|int|4291997696
/_used|int|2969600
/_total|int|4294967296
/home/bob_free|int|420968374272
/home/bob_avail|int|411116773376
/home/bob_used|int|584986157056
/home/bob_total|int|1005954531328

```

## Others
- [yambar-disk](https://github.com/Delgan/yambar-disk/tree/main): Heavily inspired by this. I would've just used it, but since I only needed to query [statvfs](https://linux.die.net/man/2/statvfs), I chose to write it directly in C. This also avoids the need to install the entire Rust toolchain.
