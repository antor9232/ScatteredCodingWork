#C way
brand ='Apple'
exchangeRate = 1.235235245
message = "The price of this %s laptop is %d USD and the exchange rate is %4.2f USD to 1 EUR" %(brand, 1299, exchangeRate)
print (message)



#Format()
message = "The price of this {0:s} laptop is {1:d} USD and the exchange rate is {2:4.2f} USD to 1 EUR".format('Apple', 1299,1.235235245)
print (message)