use warnings;
use strict;

if (@_) {
	warn "Tem argumentos";
} else {
	warn "Nao tem argumentos";
}
my $param = $_[0];
print $param;

while (my $linha = <STDIN>) {
	print $linha;
}
