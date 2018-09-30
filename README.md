# Maximal-Points-3D
In a given set of points in 3D, a point (x1,y1,z1) is said to be maximal if no other point (x2,y2,z2) is present in the given set such that x1&lt;x2 &amp; y1&lt;y2 &amp; z1&lt;z2 all simultaneously.

## Input format
First line consists of an integer specifying the number of points in the space
Second line onwards every line consists of one point each, represented by integer cordinates X Y Z seperated by a single space

input.txt is a sample input file

## Output format
First line consists of an integer specifying the number of points in the maximal set.
second line onwards every line consists of an integer no. denoting index of a maximal point in the input file, considering that indexes starts from 0.

## Execution
./run.sh Input_file_name.txt output_file_name.txt
Where Input_file_name is the name of the file from which inputs would be taken and output_file_name is the name of file where the output would be written.

Make sure that input file already exists

In case error prompts that permission is denied, execute chmao +x run.sh, and then again try.
