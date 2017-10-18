with import <nixpkgs> {};
let eclib = callPackage ./eclib.nix {};
in stdenv.mkDerivation {
  name = "env";
  buildInputs = [
    ntl
    eclib
    python3
    (callPackage ./. {})
  ];
}
