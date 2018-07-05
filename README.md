# Islandora Compound Everywhere

## Introduction

Module that creates a navigation block for non-compoundCModel compound objects, and implements a couple other refinements to the standard Compound object behavior:

1. Optionally removes an collection membership relationships from children. You should enable this option if you do not want child objects to be visible in collection browse lists.
1. Stay tuned, might be more to come....

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Compound Object Solution Pack](https://github.com/Islandora/islandora_solution_pack_compound)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

1. Configuration path is admin/islandora/tools/compound_everywhere (Administration > Islandora > Islandora Utility Modules > Islandora Compound Everywhere), where you define which content models this block should display for and other options this module provides.
1. Uncheck the "Only allow compound objects to have child objects associated with them" option at admin/islandora/solution_pack_config/compound_object (Administration > Islandora > Solution Pack Configuration > Compound Object Solution Pack.
1. Configure the "Islandora Compound Everywhere Block", as with any other block.

# Maintainer

* [Mark Jordan](https://github.com/mjordan)

## Development and feedback

Pull requests are welcome, as are use cases and suggestions. Please open an issue before creating a pull request.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
