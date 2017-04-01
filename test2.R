rm(list=ls())
data <- read.table(file = "test.txt", sep=' ')
colnames(data)<-c("nb_test","Ainit","T","result")
plot(NA, NA, xlab='T', ylab="Ainit", xlim=c(0,1500), ylim=c(0,50))
legend("topright", c("Exclusion","Cohabitation","Extinction"),col=c(rgb(1,0,0),rgb(0,1,0), rgb(0,0,1)), pch=c(19))

r <- 0
g <- 0
b <- 0

#N <- max(data["nb_test"])

l <- dim(data)[1]
for (i in 1:l){
  if (data["result"][i,]=='Cohabitation'){
    g <- 1
    r <- 0
    b <- 0
    #df[k,] <- c(r,g,b)
  }
  if (data["result"][i,]=='Exclusion'){
    r <- 1
    g <- 0
    b <- 0
    #df[k,] <- c(r,g,b)
  }
  if (data["result"][i,]=='Extinction'){
    b <- 1
    g <- 0
    r <- 0
    #df[k] <- c(r,g,b)
  }
  points(data["T"][i,], data["Ainit"][i,], pch=c(19), col=rgb(r, g, b, maxColorValue = 1))
}
