# Rule Engine LLD - .NET Implementation

A rule engine for validating business expenses, ported from Java to C#/.NET.

## 🎯 What This Project Does

This is an expense validation system that checks expenses against configurable business rules. It demonstrates several design patterns and .NET concepts.

## 📁 Project Structure

```
RuleEngineLLD/
├── Models/              # Data models (Expense, ExpenseType)
├── Services/           # Core engine logic
│   ├── Rules/         # Rule interfaces and implementations
│   │   └── Impl/      # Concrete rule implementations
│   └── Impl/          # RuleEngine implementation
├── Registry/           # Rule configuration registry
├── Utils/              # Utility helpers
└── Program.cs          # Main entry point
```

## 🚀 How to Run

### Prerequisites
- .NET SDK 9.0 or later installed
- Verify with: `dotnet --version`

### Commands

```bash
# Navigate to project directory
cd RuleEngineLLD

# Build the project
dotnet build

# Run the project
dotnet run
```

## 📚 Key .NET Concepts Used

### 1. **Namespaces**
- Like Java packages, C# uses namespaces to organize code
- Example: `namespace RuleEngineLLD.Models;`

### 2. **Interfaces**
- Define contracts (like Java interfaces)
- Prefix with `I` (e.g., `IRuleEngine`, `IExpenseRule`)
- Example: `public interface IExpenseRule { ... }`

### 3. **Properties**
- C# uses properties instead of getter methods
- `public string ExpenseId => _expenseId;` (expression-bodied property)
- `public string Message { get; }` (read-only property)

### 4. **Nullable Types**
- `Violation?` means the method can return `null` or a `Violation`
- Similar to Java's `Optional<Violation>`

### 5. **Dictionaries**
- `Dictionary<TKey, TValue>` is like Java's `Map<K, V>`
- Example: `Dictionary<ExpenseType, List<IExpenseRule>>`

### 6. **Readonly Fields**
- `readonly` fields can only be set in constructors (like Java's `final`)
- Example: `private readonly double _maxAmount;`

### 7. **Static Classes**
- Classes with only static methods
- Used for utility classes and registries

## 🔍 Understanding the Code

### Models
- **Expense.cs**: Represents an expense with immutable properties
- **ExpenseType.cs**: Enum for expense types (Restaurant, Airfare, Entertainment)

### Rules
- **IExpenseRule**: Interface for rules that validate individual expenses
- **ITripRule**: Interface for rules that validate multiple expenses together
- **Violation**: Represents a rule violation

### Rule Implementations
- **DisallowRule**: Disallows certain expense types
- **MaxAmountRule**: Checks if expense exceeds maximum amount
- **TripTotalMaxRule**: Checks if trip total exceeds maximum

### Engine
- **IRuleEngine**: Interface for the rule evaluation engine
- **SimpleRuleEngine**: Evaluates expenses against all registered rules

### Registry
- **RuleRegistry**: Central place to configure all rules
  - Restaurant expenses: max $75
  - Airfare expenses: disallowed
  - All expenses: max $200
  - Trip total: max $1000

## 🧪 Example Usage

```csharp
// Create expenses
List<Expense> expenses = new List<Expense>();
expenses.Add(new Expense("1", "1", 10.0, ExpenseType.Restaurant));
expenses.Add(new Expense("2", "1", 50.0, ExpenseType.Restaurant));
expenses.Add(new Expense("3", "1", 100.0, ExpenseType.Restaurant));

// Create and run rule engine
IRuleEngine ruleEngine = new SimpleRuleEngine();
RuleManagerRunner runner = new RuleManagerRunner(ruleEngine);
runner.Run(expenses);
```

## 🎓 Learning Path

1. **Start with Models**: Understand how `Expense` and `ExpenseType` work
2. **Study Interfaces**: See how `IExpenseRule` and `ITripRule` define contracts
3. **Examine Implementations**: Look at how rules like `MaxAmountRule` work
4. **Understand the Engine**: See how `SimpleRuleEngine` orchestrates rule evaluation
5. **Check the Registry**: See how rules are configured in `RuleRegistry`

## 🆚 Java vs C# Differences

| Java | C# |
|------|-----|
| `public final String` | `private readonly string` + Property |
| `Optional<Violation>` | `Violation?` (nullable) |
| `Map<K, V>` | `Dictionary<K, V>` |
| `List.of()` | `new List<T> { ... }` |
| `getValueOrDefault()` | `GetValueOrDefault()` |
| Packages | Namespaces |
| Interface implementation | Same (`: InterfaceName`) |

## 📝 Next Steps

- Try adding new expense types
- Create new rule types (e.g., MinAmountRule)
- Modify rules in `RuleRegistry`
- Add more test cases in `Program.cs`

## 🔗 Original Java Project

This is a port of: https://github.com/singhsanket143/RuleEngineLLD

