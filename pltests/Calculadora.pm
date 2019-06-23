package Calculadora;

use warnings;
use strict;

sub soma {
	return $_[0] + $_[1];
}

sub import {
	warn "IMPORTING!";
}

1;
