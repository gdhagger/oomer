# OOMER

`oomer` is a tiny docker image that intentionally uses all available memory quickly to trigger the host system's OOM-Killer.

It serves no useful purpose other than allowing us to test handling of OOMs by surrounding systems.

## Requirements

### Ubuntu
```
apt install musl-dev musl-tools
```

## Build
```
make build
```

## Package
```
make package
```