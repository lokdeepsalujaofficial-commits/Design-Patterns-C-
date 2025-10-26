namespace RuleEngineLLD.Models;

/// <summary>
/// Represents an expense with immutable properties.
/// In C#, 'readonly' fields can only be set in the constructor (similar to Java's 'final').
/// </summary>
public class Expense
{
    private readonly string _expenseId;
    private readonly string _tripId;
    private readonly double _amountUsd;
    private readonly ExpenseType _expenseType;

    // Constructor - sets all readonly fields
    public Expense(string expenseId, string tripId, double amountUsd, ExpenseType expenseType)
    {
        _expenseId = expenseId;
        _tripId = tripId;
        _amountUsd = amountUsd;
        _expenseType = expenseType;
    }

    // Properties - C# uses { get; } for read-only properties
    public string ExpenseId => _expenseId;
    public string TripId => _tripId;
    public double AmountUsd => _amountUsd;
    public ExpenseType ExpenseType => _expenseType;
}

