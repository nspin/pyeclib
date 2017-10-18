{stdenv, fetchFromGitHub, autoconf, automake, libtool, gettext, autoreconfHook
, pari, ntl, gmp}:

stdenv.mkDerivation rec {
  name = "${pname}-${version}";
  pname = "eclib";
  version = "v20171002";
  src = fetchFromGitHub {
    owner = "JohnCremona";
    repo = "${pname}";
    rev = "${version}";
    sha256 = "092an90405q9da0k0z5jfp5rng9jl0mqbvsbv4fx6jc9ykfcahsj";
  };
  buildInputs = [pari ntl gmp];
  nativeBuildInputs = [autoconf automake libtool gettext autoreconfHook];
  meta = {
    inherit version;
    description = ''Elliptic curve tools'';
    license = stdenv.lib.licenses.gpl2Plus;
    maintainers = [stdenv.lib.maintainers.raskin];
    platforms = stdenv.lib.platforms.linux;
  };
}
