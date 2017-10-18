{ callPackage, python3Packages, ntl }:

let eclib = callPackage ./eclib.nix {};

in python3Packages.buildPythonPackage rec {
  version = "0.0.1";
  pname = "pyeclib";
  name = "${pname}-${version}";
  src = ./.;
  propagatedBuildInputs = [ ntl eclib ];
}
