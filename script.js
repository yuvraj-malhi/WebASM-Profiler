let wasmExports = null;

let wasmMemory = new WebAssembly.Memory({initial: 1024, maximum: 65536});

let wasmTable = new WebAssembly.Table({
    'initial': 1,
    'maximum': 1,
    'element': 'anyfunc'
});

let asmLibraryArg = { 
    "__handle_stack_overflow": ()=>{},
    "emscripten_resize_heap": ()=>{},
    "__lock": ()=>{}, 
    "__unlock": ()=>{},
    "memory": wasmMemory, 
    "table": wasmTable 
};

var info = {
    'env': asmLibraryArg,
    'wasi_snapshot_preview1': asmLibraryArg
};

async function loadWasm(){
    let response = await fetch('arithmeticWS.wasm');
    let bytes = await response.arrayBuffer();
    let wasmObj = await WebAssembly.instantiate(bytes, info);
    wasmExports = wasmObj.instance.exports;
}

loadWasm();