#!/usr/bin/perl
use strict;

if(@ARGV < 1){
    print "usage: $0 num_to_be_gengerated\n";
    exit;
}

my $num = @ARGV[0];

open TEST_TXT,"> ./test.in" or die "$!";

srand;
my $count = 0;
while($count < $num){
    my $i = int(rand(4294967295));
    print TEST_TXT $i, " "; 
    $count ++;
}
print TEST_TXT "\n";
close TEST_TXT;
