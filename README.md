# Go binding for yara

This repository is a repackages go-yara and libyara c files in such a
way that they can built using cgo statically without needing to link
a shared object.

# Current Versions:

* Libyara version is v4.5.4
* go-yara version is v4.3.2

# Enabled modules

Only the following yara modules are available. Rules that import other
modules will be rejected.

* pe
* elf
* math
* time
* dotnet

# NOTE: This package does not build with openssl support.

Openssl is considered a large and complex dependency so at present it
is not built into the library.

This means that any functionality that requires openssl will not work!

Specifically the following fields in the pe module are not populated
and will not work in conditions:

* pe.signatures
* pe.is_signed
* pe.number_of_signatures

In previous versions these fields were completely removed but this
caused rules that use those fields to be rejected outright. This
caused problems when loading a large number of rules from external
sources, because it is difficult to identify and remove just the
offending rules.

In this version, the fields are defined but are never populated. This
allows rules that reference those fields to be loaded cleanly but any
conditions will not match. Considering that signatures can be easily
invalidated, robust rules typically have other conditions as a
fallback so the impact should be minimal.
