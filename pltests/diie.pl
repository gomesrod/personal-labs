use strict;
use warnings;

my $var1;
print defined($var1) ? "defined\n" : "not defined\n";

$var1 = 1;
print defined($var1) ? "defined\n" : "not defined\n";

$var1 = undef;
print defined($var1) ? "defined\n" : "not defined\n";


defined($var1) or die "ERRO vacilao!";

