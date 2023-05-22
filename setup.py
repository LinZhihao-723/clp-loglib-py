import os
from setuptools import setup, Extension

clp_ir_encoder: Extension = Extension(
    name="clp_logging.CLPNativeEncoder",
    language="c++",
    sources=[
        "src/clp_ffi/clp/components/core/src/ffi/ir_stream/encoding_methods.cpp",
        "src/clp_ffi/clp/components/core/src/ffi/encoding_methods.cpp",
        "src/clp_ffi/clp/components/core/src/string_utils.cpp",
        "src/clp_ffi/clp/components/core/src/TraceableException.cpp",
        "src/clp_ffi/clp_loglib_native/clp_native_encoder.cpp",
        "src/clp_ffi/clp_loglib_native/encoding_method.cpp"
    ],
    extra_compile_args=[
        '-std=c++17',
        "-O3"
    ],
    define_macros=[
        ("SOURCE_PATH_SIZE", str(len(os.path.abspath("./src/clp_ffi/clp/components/core"))))
    ]
)


setup(
    name="clp_logging",
    version="0.0",
    description="CLP Native IR Encoder",
    ext_modules=[clp_ir_encoder],
    packages=["clp_logging"],
)
