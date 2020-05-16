# Another ray tracer written on C.

![Generated picture example](/examples/picture.png)

## How to run

```sh
make ray_tracer
./ray_tracer
```

## Acknowledgements

1. The C Programming Language, book by Brian Kernighan and Dennis Ritchie.
2. This gist and all acknowledgements from it: https://gist.github.com/sevko/c3ed2430e96b89dd3177
3. This article (russian): https://habr.com/ru/post/187720/
4. Wikipedia: bunch of articles about lambertian diffusion, ppm format and other stuff.
5. This guy suggested include guard: https://github.com/zipfile

## TODO

1. Move material inside sphere structure, remove crap with access to material by index.
2. Add shadows.
3. Add png support (probably write handmade parser...).
4. Add `.obj` files support (with textures).
5. Add background support.
6. Antialiasing and all advanced things.
7. Rendering in multiple threads.
8. GPU-based rendering.
9. Probably rendering on gpu cluster.
