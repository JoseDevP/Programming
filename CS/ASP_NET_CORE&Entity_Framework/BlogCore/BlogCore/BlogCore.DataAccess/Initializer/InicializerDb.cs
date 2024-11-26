using BlogCore.Data;
using BlogCore.Models;
using BlogCore.Utilities;
using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Initializer
{
    public class InicializerDb : IInicializerDb
    {
        private readonly ApplicationDbContext _dbContext;
        private readonly UserManager<ApplicationUser> _userManager;
        private readonly RoleManager<IdentityRole> _roleManager;

        public InicializerDb(ApplicationDbContext dbContext,
            UserManager<ApplicationUser> userManager,
            RoleManager<IdentityRole> roleManager)
        {
            _dbContext = dbContext;
            _userManager = userManager;
            _roleManager = roleManager;
        }

        public async Task Inicialize()
        {
            try
            {
                if ((await _dbContext.Database.GetAppliedMigrationsAsync()).Any())
                {
                    await _dbContext.Database.MigrateAsync();
                    Console.WriteLine("Database migration applied.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Migration Error: {ex.Message}");
            }

            if (_dbContext.Roles.Any(ro => ro.Name == CNT.Administrator))
            {
                Console.WriteLine("Roles already exist. Exiting seeding.");
                return;
            }

            try
            {
                // Create roles
                await _roleManager.CreateAsync(new IdentityRole(CNT.Administrator));
                await _roleManager.CreateAsync(new IdentityRole(CNT.Registered));
                await _roleManager.CreateAsync(new IdentityRole(CNT.Client));
                Console.WriteLine("Roles created.");

                // Create initial user
                var user = new ApplicationUser
                {
                    UserName = "jose@gmail.com",
                    Email = "jose@gmail.com",
                    EmailConfirmed = true,
                    NormalizedUserName = "JOSE",
                    Name = "Jose"
                };

                var result = await _userManager.CreateAsync(user, "Admin1234*");

                if (result.Succeeded)
                {
                    ApplicationUser createdUser = await _dbContext.ApplicationUsers
                        .Where(us => us.Email == "jose@gmail.com")
                        .FirstOrDefaultAsync();

                    await _userManager.AddToRoleAsync(createdUser, CNT.Administrator);
                    Console.WriteLine("Initial user created and assigned to Administrator role.");
                }
                else
                {
                    foreach (var error in result.Errors)
                    {
                        Console.WriteLine($"Error: {error.Description}");
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Seeding Error: {ex.Message}");
            }
        }

    }
}
