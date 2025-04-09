namespace GameEngine.Adapters;

public struct CircleAdapter() : IDrawable
{
    private CircleShape _binding = new();

    public CircleAdapter(object drawable) : this()
    {
        _binding = (CircleShape)drawable ?? throw new NullReferenceException();
    }

    public readonly IDrawable SetBackgroundColor(EColor color) { _binding.FillColor = color.ToColor(); return this; }
    public readonly IDrawable SetBorderColor(EColor color) { _binding.OutlineColor = color.ToColor(); return this; }
    public readonly IDrawable SetBorderSize(VectorAdapter vector) { _binding.OutlineThickness = vector.X; return this; }
    public readonly IDrawable SetSize(VectorAdapter vector) { _binding.Radius = vector.X / 2; return this; }
    public readonly IDrawable SetPosition(VectorAdapter vector) { _binding.Position = vector; return this; }
    public readonly IDrawable SetScale(VectorAdapter vector) { _binding.Scale = vector; return this; }
    public readonly IDrawable SetRotation(float rotation) { _binding.Rotation = rotation; return this; }
    public readonly IDrawable SetTexture(TextureAdapter texture) { _binding.Texture = texture; ; return this; }

    public readonly object GetDrawable() => _binding;
    public readonly EColor GetBackgroundColor() => _binding.FillColor.ToEnum();
    public readonly EColor GetBorderColor() => _binding.OutlineColor.ToEnum();
    public readonly RectAdapter GetBounds() => _binding.GetGlobalBounds();
    public readonly VectorAdapter GetBorderSize() => new(_binding.OutlineThickness, 0);
    public readonly VectorAdapter GetSize() => GetBounds().Size();
    public readonly VectorAdapter GetPosition() => _binding.Position;
    public readonly VectorAdapter GetScale() => _binding.Scale;
    public readonly float GetRotation() => _binding.Rotation;
    public readonly TextureAdapter GetTexture() => _binding.Texture;

    public void Dispose()
    {
        _binding.Dispose();
        _binding = null;
    }

    public static implicit operator CircleShape(CircleAdapter adapter) => (CircleShape)adapter.GetDrawable();

    public static implicit operator CircleAdapter(CircleShape drawable) => new(drawable);
}
