rm(list=ls())

data <- read.table(file = "/home/sgonthier/Documents/C C++/test.txt", sep=' ')
colnames(data)<-c("nb_test","Ainit","T","result")
print(data)
n_test <- max(data$nb_test)
n_param <- length(data$nb_test==1)/n_test
plot(NA, NA, xlab='T', ylab="Ainit", xlim=c(0,1500), ylim=c(0,50))
legend("topright", c("Extinction","Exclusion", "Cohabitation"),col=c(rgb(1,0,0),rgb(0,1,0), rgb(0,0,1)), pch=c(19))
for (param in 1:n_param) {
  r <- 0
  g <- 0
  b <- 0
  for (test in 1:n_test) {
    if(data[(n_param*(param-1)+test),]$result == 'Extinction'){ 
      r <- r+1 
    } else if(data[(n_param*(param-1)+test),]$result == 'Exclusion'){ 
      g <- g+1
    } else if(data[(n_param*(param-1)+test),]$result == 'Cohabitation'){ 
      b <- b+1 
    } else { 
      print("We have a problem") 
    }
  }
  r <- r/n_test
  g <- g/n_test
  b <- b/n_test
  points(data[(n_param*(param-1)+test),]$"T", data[(n_param*(param-1)+test),]$"Ainit", pch=c(19), col=rgb(r, g, b, maxColorValue = 1))
  print(c(r,g,b))
}
#typeof(data[(1),]$result)
#typeof(as.factor('Extinction'))
