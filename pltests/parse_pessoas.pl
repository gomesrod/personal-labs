use strict;
use warnings;
use Pessoa;

open (my $file, "<pessoas.txt");

while (<$file>) {
	my $line = $_;
	chomp($line);
	
	next if ($line =~ /^\s*$/);

	if (not $line =~ m{Nome: (\w+), Sobrenome: (\w+), Data Nascimento: (\d\d)/(\d\d)/(\d\d\d\d)}) {
		print ">>> " . $line;
		die "Formato invalido na linha";
	}

	my $pessoa = Pessoa::New();
	$pessoa->{nome} = $1;
	$pessoa->{sobrenome} = $2;
	$pessoa->{diaNasc} = $3;
	$pessoa->{mesNasc} = $4;
	$pessoa->{anoNasc} = $5;

	print "::: " . $pessoa->{nome} . " " . $pessoa->{sobrenome} . ", "  . $pessoa->formatarDataNasc() . ", " . $pessoa->calcularIdade();
	print "\n";
}

close($file);
