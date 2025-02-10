select * from Users
where mail ~* '^[a-z]([a-z0-9_\.\-])*?@leetcode\.com$'
