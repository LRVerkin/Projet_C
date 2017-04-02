rm(list=ls())
data <- read.table(file = "test.txt", sep=' ')
colnames(data)<-c("nb_test","Ainit","T","result")
plot(NA, NA, xlab='T', ylab="Ainit", xlim=c(0,1500), ylim=c(0,50))
legend("topright", c("Exclusion","Cohabitation","Extinction"),col=c(rgb(1,0,0),rgb(0,1,0), rgb(0,0,1)), pch=c(19))

N <- max(data["nb_test"])
L <- length(data$nb_test==1)/N

for (test in 1:N){
  for (i in 1:L){
    r <- 0
    g <- 0
    b <- 0
    if (data["result"][(test-1)*30+i,]=='Cohabitation'){
      g <- g+1
    }
    
    if (data["result"][(test-1)*30+i,]=='Exclusion'){
      r <- r+1
    }
    
    if (data["result"][(test-1)*30+i,]=='Extinction'){
      b <- b+1
    }
    
    r <- r/N
    b <- b/N
    g <- g/N
    points(data["T"][(test-1)*30+i,], data["Ainit"][(test-1)*30+i,], pch=c(19), col=rgb(r, g, b, maxColorValue = 1))
  }
}
