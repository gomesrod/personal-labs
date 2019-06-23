package Conta;
use strict;
use warnings;

sub New {
	my $obj = {};
	$obj->{saldo} = 0.0;
	bless($obj, "Conta");
	return $obj;
}

sub Depositar {
	my ($obj, $valor) = @_;
	$obj->{saldo} += $valor;
}

sub Sacar {
	my ($obj, $valor) = @_;
	$obj->{saldo} -= $valor;
}

sub Saldo {
	my $obj = @_;
	return ${$obj->{saldo}};
}

1;
