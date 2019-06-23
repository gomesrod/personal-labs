package Pessoa;
use strict;
use warnings;
use Time::Local;

#/
# Classe Pessoa
# Possui os seguintes atributos:
#
# $pessoa->{nome} 
# $pessoa->{sobrenome}
# $pessoa->{diaNasc}
# $pessoa->{mesNasc}
# $pessoa->{anoNasc}
#
#/
sub New {
	return bless({}, "Pessoa");
}

sub formatarDataNasc {
	my $this = $_[0];
	return $this->{diaNasc}. "/" . $this->{mesNasc} . "/" . $this->{anoNasc}
}

sub calcularIdade {
	my $this = $_[0];
	my $nasc = timelocal(0, 0, 0, $this->{diaNasc}, $this->{mesNasc} - 1, $this->{anoNasc});
	warn 
	warn "nasc " . $nasc;
	my $hoje = time();
	warn "hoje " . $hoje;

	my $diff = $hoje - $nasc;
	warn "diff " . $diff;
	my $diff_in_years = $diff / (60 * 60 * 24 * 30 * 12);
	return $diff_in_years;	
}

1;
