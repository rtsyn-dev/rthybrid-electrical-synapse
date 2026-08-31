# RTHybrid Electrical Synapse

Computes an electrical synapse current from pre and post voltages.

This is a C RTSyn module ported from the older RTHybrid RTSyn plugin tree. Load the module by selecting this
repository's `xmake.lua`; the RTSyn module loader will build the shared library and load the descriptor.

## Build

```sh
RTSYN_WORKSPACE=/home/seregio/Desktop/stuff/projects/rtsyn xmake f -c -y
RTSYN_WORKSPACE=/home/seregio/Desktop/stuff/projects/rtsyn xmake
```
