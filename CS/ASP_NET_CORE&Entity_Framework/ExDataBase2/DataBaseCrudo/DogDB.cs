using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataBase2
{
    public class DogDB : DB
    {
        public DogDB(string server, string db, string user, string pasword) : base(server, db, user, pasword) { }

        public List<Dog> ShowAllDogs()
        {
            Connect();

            List<Dog> dogList = new List<Dog>();

            string query = "SELECT * FROM Dog";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            while (reader.Read())
            {
                int id = reader.GetInt32(0);
                string name = reader.GetString(1);
                int breedId = reader.GetInt32(2);
                dogList.Add(new Dog(id,name,breedId));
            }

            Close();

            return dogList;
        }

        public List<Breed> ShowAllBreeds()
        {
            Connect();

            List<Breed> breedList = new List<Breed>();

            string query = "SELECT * FROM Breed";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            SqlDataReader reader = sqlCommand.ExecuteReader();
            while (reader.Read())
            {
                int id = reader.GetInt32(0);
                string name = reader.GetString(1);
                breedList.Add(new Breed(id,name));
            }

            Close();

            return breedList;
        }

        public void AddDog(Dog dog)
        {
            Connect();
            string query = "INSERT INTO Dog(Name, BreedId) " +
                "VALUES(@name, @BreedId)";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@name", dog.Name);
            sqlCommand.Parameters.AddWithValue("@BreedId", dog.BreedID);

            sqlCommand.ExecuteNonQuery();

            Close();
        }

        public Dog GetDog(int id)
        {
            Connect();

            Dog dog = null;

            string query = "SELECT * FROM Dog "
                + "WHERE ID=@id";
            SqlCommand sqlCommand = new SqlCommand(query,_connection);
            sqlCommand.Parameters.AddWithValue("@id", id);

            SqlDataReader reader = sqlCommand.ExecuteReader();

            while (reader.Read())
            {
                string name = reader.GetString(1);
                int breedId = reader.GetInt32(2);

                dog = new Dog(id, name, breedId);
            }

            Close();

            return dog;
        }

        public Breed GetBreed(int id)
        {
            Connect();

            Breed breed = null;

            string query = "SELECT * FROM Breed "
                + "WHERE ID=@id";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@id", id);

            SqlDataReader reader = sqlCommand.ExecuteReader();

            while (reader.Read())
            {
                string name = reader.GetString(1);

                breed = new Breed(id, name);
            }

            Close();

            return breed;
        }

        public void AddBreed(Breed breed)
        {
            Connect();
            string query = "INSERT INTO Breed(Name) " +
                "VALUES(@name)";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@name", breed.Name);

            sqlCommand.ExecuteNonQuery();

            Close();
        }

        public void EditDog(Dog dog)
        {
            Connect();

            string query = "UPDATE Dog SET Name=@name, BreedID=@breedId " +
                "WHERE id=@id";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@name", dog.Name);
            sqlCommand.Parameters.AddWithValue("@breedId", dog.BreedID);
            sqlCommand.Parameters.AddWithValue("@id", dog.ID);

            sqlCommand.ExecuteNonQuery();

            Close();
        }

        public void EditBreed(Breed breed)
        {
            Connect();

            string query = "UPDATE Breed SET Name=@name " +
                "WHERE id=@id";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@name", breed.Name);
            sqlCommand.Parameters.AddWithValue("@id", breed.ID);

            sqlCommand.ExecuteNonQuery();

            Close();
        }

        public void DeleteDog(int id) 
        {  
            Connect();

            string query = "DELETE FROM Dog WHERE ID=@id";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@id", id);
            sqlCommand.ExecuteNonQuery();

            Close();
        }

        public void DeleteBreed(int id)
        {
            Connect();

            string query = "DELETE FROM Breed WHERE ID=@id";
            SqlCommand sqlCommand = new SqlCommand(query, _connection);
            sqlCommand.Parameters.AddWithValue("@id", id);
            sqlCommand.ExecuteNonQuery();

            Close();
        }
    }
}
