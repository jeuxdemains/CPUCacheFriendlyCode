# CPUCacheFriendlyCode
This is an example on how to write CPU cache friendly code and a comparison measure against non cache friendly one.

It's good if you have some basic knowledge of the different CPU cache levels and how they work as well as cache lines etc.
However, this example should be suficient enough to demonstrate the basic idea even if you just take it for granted and not dig deeply into the hardware details.

Prerequisites: 
Dynamically created objects: 3_500_000
Each object gets associated number of sub-components: 6

Stats on AMD Ryzen 9500X system:
- Non cache friendly time of execution: ~3433 milliseconds
- Cache friendly time of execution: ~897 milliseconds

That's around 117% faster.
