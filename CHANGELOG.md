# Change Log

All notable changes to the "cfa-tools" extension will be documented in this file.


## [Unreleased]


## [0.1.0] - 2025-12-23

### Added

- Typescript/Node boilerplate code and manifest setup for starting LSP
- Dynamic memory allocation keywords -- `new`, `delete`, `anew`, `adelete`
- Future (`future_rc`) control flow keywords added -- `waituntil`, `and`, `or`
- Null pointer literal (`0p`) recognized

### Changed
- Renamed file `LICENCE` to `LICENSE`
- Folding and indentation patters updated to common C/C++ extension style patterns

### Fixed

- Certain control flow keywords now highlighted properly -- `fallthrough`, `waitfor`


## [0.0.2] - 2025-09-18

### Added

- Both icons in different square dimensions (old: 32,1024, new: 16,48,64,128)

### Changed

- Project name to `cfa-tools` - propagated to all documentation files
- `package.json`: included [Github repo](https://github.com/The-Ahmed-Shahriar/cfa-tools#readme) links.
- `.gitignore`, `.vscodeignore`: synced


## [0.0.1] - 2025-09-17

### Added

- Initial release
