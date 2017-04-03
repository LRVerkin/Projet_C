rm(list=ls())
data <- read.table(file = "test.txt", sep=' ')
colnames(data)<-c("nb_test","Ainit","T","result","LCell","SCell")
plot(NA, NA, xlab='T', ylab="Ainit", xlim=c(0,1500), ylim=c(0,50))
legend("topright", c("Exclusion","Cohabitation","Extinction"),col=c(rgb(1,0,0),rgb(0,1,0), rgb(0,0,1)), pch=c(19))

N <- max(data["nb_test"]) # nombre de tests que l'on veut réaliser
L <- length(data$nb_test==1)/N # nombre de "couples de paramètres" par test
n_LCell <- as.numeric(data[,5])
n_SCell <- as.numeric(data[,6])
ratio <- n_SCell/(n_LCell+n_SCell)

for (i in 1:L){
  r <- 1-ratio[i]
  g <- ratio[i]
  points(data["T"][i,], data["Ainit"][i,], pch=c(19), col=rgb(r, g, 0, maxColorValue = 1))
}

