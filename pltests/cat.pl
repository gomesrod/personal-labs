require warnings;
require strict;

my $in = STDIN;
(<$in>) or die "Nenhum dado";
my $linha = $_;

print "LEU: " . $linha . "\n";

