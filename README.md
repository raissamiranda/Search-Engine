# URL Scheduler

The main component of a search engine is a collector. With the large number os existing URLs actually, it's necessary to use a scheduler to define the collection order of the pages. An URL follows the format:
> -protocol-://-host--path-?-query-#-fragment-
  
The collector developed in this project, with no use of STL or other libraries, uses the depth-first strategy, which priorizes sites and URLs found first. The depth criterion priorizes URLs closer to the root of the site, that is:
> http:://ufmg.br 

must be collected before 
> http:://ufmg.br/dcc

## Execution's instructions
To install the program, it is necessary to acess the diretory where the program is stored
> cd -directory-

Now, you must execute the make command and run the program with the name of the test .txt file:
> make
> 
> cd bin
> 
> ./ main -pathtotest-

A file will be created with the same name as the input file, but with the suffix -out in the same directory with the output data.


