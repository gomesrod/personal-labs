use strict;
use warnings;

my $pi = 3.14;
print $pi;
print "\n";
my $name = 'john doe';
print $name;
print "\n";

my $nomeref = \$name;
print $nomeref . "    " . $$nomeref;
print "\n";

$name = 'ze';
print $name;
print "\n";


my ($first, $last) = qw (Foo Bar);
print "$first\n";
print "$last\n";


my @arra = qw (Arrr Ayyyy);
print @arra[0] . "\n";
print @arra[1] . "\n";


