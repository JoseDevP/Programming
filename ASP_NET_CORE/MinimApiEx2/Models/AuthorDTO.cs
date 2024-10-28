public class AuthorDTO
{ 
    public int Id { get; set; }

    public string Name { get; set; }
    public DateTime DateOfBirth { get; set; }

    public AuthorDTO() {}

    public AuthorDTO(Author author)
    {
        Id = author.Id; 
        Name = author.Name;
        DateOfBirth = author.DateOfBirth;
    }

}