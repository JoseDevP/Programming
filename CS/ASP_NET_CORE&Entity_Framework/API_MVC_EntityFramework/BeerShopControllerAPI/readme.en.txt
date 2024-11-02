In this project, we are working on the backend of a fictional beer purchasing store. 
It is an API that allows us to connect to a database of a fictional beer store,
which has tables for each type of beer and each type of beer brand.

The data is stored in the "Models" folder. Here we have Beer, representing the Beers table in the database; 
Brand, representing the Brands table in the database; and StoreContext, 
representing the database context to be injected from Program to the builder. 
In this case, Entity Framework is used in Code First mode. Therefore, migrations are created from the code, 
which are saved in the "Migrations" folder, and then, thanks to Entity Framework, the database is created/updated. Additionally, 
I have injected the context into a repository, which I will discuss later.

To determine the information we send, we have a series of Document Transfer Objects (DTO) for Beer, located in the "DTO" folder. 
These include BeerDTO, which we use to return general information that 
includes all parameters; BeerInsertDTO, which we use when we want to add a new Beer; and BeerUpdateDTO, 
which we will use when we want to modify a Beer.

The controllers (in the "Controllers" folder) are responsible for receiving HTTP requests and returning a response. 
BeerController has a series of HTTP methods to manage HTTP GET, POST, PUT, and DELETE requests. 
It only handles receiving and returning requests, with a response code and a body containing the DTO. Therefore, 
the business logic and validations are not handled directly by the controller; instead, by injecting dependencies 
from Program, we can distribute functionalities more effectively.

The validations are found in the "Validators" folder. In this case, I decided to use a library called FluentValidation, 
which allows us to separate the validations of the DTO. We have two classes for validations: BeerInsertValidator for 
insertion validations, with a series of conditions, and BeerUpdateValidator for update validations. The validation 
dependencies are injected into the controller so that if the validations fail, it returns an error code.

Next, the controller checks if there have been any errors. In this case, instead of handling errors using exceptions, 
I opted for an alternative method that I believe can manage them better. In this case, in the BeerService 
(which implements an interface and class) that I will discuss in more detail below, I created a list of strings 
called Errors and two validation methods that will use the repository's Search method. This method receives a 
lambda expression indicating that if the specified condition is found, it will return a boolean, and we can add 
the corresponding error to the error list, which can then be retrieved in the controller to indicate the type 
of error to the API consumer.

The next step the controller takes is to manage the logic. For this, thanks to the injected dependency of the 
service (found in the "Services" folder) BeerService, which, as I mentioned earlier, implements error validation, 
but also has its own methods to manage business logic. In this case, it usually communicates with an injected 
repository in it called BeerRepository, which will handle communication with the database.

Once all this is done, the controllers will return a message in one way or another, depending on whether the 
process was successful or not.

Finally, I would like to explain that to avoid having to create a DTO from a Beer class object or vice versa 
each time, AutoMapper has been used to simplify this process.

This same process is also used with beer brands.
