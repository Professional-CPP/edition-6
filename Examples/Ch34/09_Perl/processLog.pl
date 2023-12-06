#! /usr/bin/perl

open (INPUT, "userlog.txt") or die "Couldn't open input file!";
open (OUTPUT, ">userlog.out") or die "Couldn't open output file!";

while ($line = <INPUT>) {
    if ($line =~ m/^Password: (.*)/) {
        $result = `./encryptString $1`;
        if ($? != 0) { exit(-1); }
        print OUTPUT "Password: $result\n";
    } else {
        print OUTPUT "$line";
    }
}

close (INPUT);
close (OUTPUT);
