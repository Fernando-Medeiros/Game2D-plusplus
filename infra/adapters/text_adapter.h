namespace GameEngine.Adapters;

public struct TextAdapter() : IDrawable
{
    private Text _binding = new();

    public TextAdapter(object drawable) : this()
    {
        _binding = (Text)drawable ?? throw new NullReferenceException();
    }

    public readonly IDrawable SetBackgroundColor(EColor color) { _binding.FillColor = color.ToColor(); return this; }
    public readonly IDrawable SetBorderColor(EColor color) { _binding.OutlineColor = color.ToColor(); return this; }
    public readonly IDrawable SetBorderSize(VectorAdapter vector) { _binding.OutlineThickness = vector.X; return this; }
    public readonly IDrawable SetSize(VectorAdapter vector) { _binding.CharacterSize = (uint)vector.X; return this; }
    public readonly IDrawable SetPosition(VectorAdapter vector) { _binding.Position = vector; return this; }
    public readonly IDrawable SetScale(VectorAdapter vector) { _binding.Scale = vector; return this; }
    public readonly IDrawable SetRotation(float rotation) { _binding.Rotation = rotation; return this; }
    public readonly IDrawable SetFont(FontAdapter font) { _binding.Font = font; return this; }
    public readonly IDrawable SetText(string text) { _binding.DisplayedString = text; return this; }
    public readonly IDrawable SetStyle(EFontStyle style) { _binding.Style = style.ToStyle(); return this; }

    public readonly object GetDrawable() => _binding;
    public readonly string GetText() => _binding.DisplayedString;
    public readonly EColor GetBackgroundColor() => _binding.FillColor.ToEnum();
    public readonly EColor GetBorderColor() => _binding.OutlineColor.ToEnum();
    public readonly FontAdapter GetFont() => _binding.Font;
    public readonly RectAdapter GetBounds() => _binding.GetGlobalBounds();
    public readonly VectorAdapter GetBorderSize() => (_binding.OutlineThickness, 0f);
    public readonly VectorAdapter GetSize() => GetBounds().Size();
    public readonly VectorAdapter GetPosition() => _binding.Position;
    public readonly VectorAdapter GetScale() => _binding.Scale;
    public readonly float GetRotation() => _binding.Rotation;

    public void Dispose()
    {
        _binding.Dispose();
        _binding = null;
    }

    public static implicit operator Text(TextAdapter adapter) => (Text)adapter.GetDrawable();

    public static implicit operator TextAdapter(Text drawable) => new(drawable);
}
