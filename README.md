# Deconvolute
Combines reads and places in to fastq.gz file based on indexes in reads

These programs reads NGS fastq.gz files and combines read 1 and 2 to a single PCR sequence with the reads placed into sample specific file fastq.gz files.

## Plain:
The indexes and primer sequences are a fixed distance from the start

## Staggered:
The index and primer sequences are a variable distance from start. This is to increase the variation in bases to make base calling better.
