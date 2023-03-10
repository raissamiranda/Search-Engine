# URL Scheduler

The main component of a search engine is a collector. With the large number os existing URLs actually, it's necessary to use a scheduler to define the collection order of the pages. An URL follows the format:
> -protocol-://-host--path-?-query-#-fragment-
> <<protocol>>://<<host>><<path>>?<<query>>#<<fragment>>
  
The collector developed in this project uses the depth-first strategy, which priorizes sites and URLs found first. The depth criterion priorizes URLs closer to the root of the site, that is:
> http:://ufmg.br 

must be collected before 
> http:://ufmg.br/dcc
