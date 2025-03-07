# ESPHome-packages

## Usage example:

```
packages:
  remote_package:
    url: https://github.com/sergeysaley/ESPHome-packages
    files: [
      packages/common.yaml,
      packages/item.yaml
    ]
    ref: main
    refresh: 0s
```
Specific values written inn main file overrides package values

Substitutions from main file work in packages files
