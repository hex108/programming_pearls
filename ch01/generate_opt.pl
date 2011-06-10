#!/usr/bin/perl
use strict;

my @numbers;

open TEST_TXT,"> ./test.txt" or die "$!";

srand;
my $total = 10000000;
my $remain = $total;
my $needed = 1000000; 
for(my $i = 1; $i <= $total ; $i ++){
    my $j = int(rand($remain));
    if($j < $needed){
        push @numbers, $i;
        print TEST_TXT $i, " "; 
        $needed --;
        if($needed == 0){
            last;
        }
    }
    $remain --;
}
print TEST_TXT "\n";
close TEST_TXT;

open TEST_OUT, "> ./test.out" or die "$!";
print TEST_OUT join "\n",sort {$a <=> $b} @numbers;
print TEST_OUT "\n";
close TEST_OUT;
