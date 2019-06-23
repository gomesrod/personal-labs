use warnings;
use strict;
use Data::Dumper;

my @months;
$months[1] = "January";
$months[5] = "May";

print Dumper \@months;

my @animals = "cat";

print Dumper \@animals;

my $sca = scalar(@animals);

println($sca);

@animals = ("cat", "dog", "fish");

print Dumper \@animals;

println(scalar(@animals));

foreach my $anim (@animals) {
	println("ANIMAL -> ". $anim);
}

my @nums = (1=>'um', 2=>'dois', 3=>'tres');
print Dumper \@nums;

sub println {
	print $_[0] . "\n";
}
