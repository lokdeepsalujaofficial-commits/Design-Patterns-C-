using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;

namespace RuleEngineLLD.Services.Rules.Impl;

/// <summary>
/// Rule that disallows certain expense types.
/// In C#, 'class ClassName : InterfaceName' means the class implements the interface.
/// </summary>
public class DisallowRule : IExpenseRule
{
    /// <summary>
    /// Always returns a violation - this rule disallows the expense type entirely.
    /// </summary>
    public Violation? Check(Expense expense)
    {
        return Violation.Of($"Expense type {expense.ExpenseType} id:{expense.ExpenseId} is not allowed");
    }
}

