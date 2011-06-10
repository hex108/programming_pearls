#!/usr/bin/perl
use strict;

my $num = 0;
my %hash;

open TEST_TXT,"> ./test.txt" or die "$!";

srand;
my $need = 10000000;
my $total = 100000000;
while($num < $need){
    my $i = int(rand($total));
    if(!exists $hash{$i}){
        $hash{$i} = 1;
        print TEST_TXT $i, " "; 
        $num ++;
    }
}
print TEST_TXT "\n";
close TEST_TXT;

open TEST_OUT, "> ./test.out" or die "$!";
print TEST_OUT join "\n",sort {$a <=> $b} keys %hash;
print TEST_OUT "\n";
close TEST_OUT;
