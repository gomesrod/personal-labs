use strict;
use warnings;
use Conta;
use Data::Dumper;

my $conta = Conta->New();

print Dumper $conta;

$conta->Depositar(500.00);

print Dumper $conta;

$conta->Sacar(220.00);

print Dumper $conta;

my $msg = "(
*******************************
Saldo final: " . ($conta->Saldo) . "

*******************************
)";

print $msg;
