﻿using BlogCore.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.DataAccess.Data.Repository.IRepository
{
    public interface IArticleRepository : IRepository<Article>
    {
        Task Update(Article article);

        IQueryable<Article> AsQueryable();
    }
}
