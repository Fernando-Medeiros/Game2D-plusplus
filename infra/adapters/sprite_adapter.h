namespace GameEngine.Adapters;

public struct SpriteAdapter() : IDrawable
{
    private Sprite _binding;

    public SpriteAdapter(object drawable) : this()
    {
        _binding = (Sprite)drawable ?? throw new NullReferenceException();
    }

    public readonly IDrawable SetBackgroundColor(EColor color) { _binding.Color = color.ToColor(); return this; }
    public readonly IDrawable SetBorderColor(EColor color) { return this; }
    public readonly IDrawable SetBorderSize(VectorAdapter vector) { return this; }
    public readonly IDrawable SetSize(VectorAdapter vector) { return this; }
    public readonly IDrawable SetPosition(VectorAdapter vector) { _binding.Position = vector; return this; }
    public readonly IDrawable SetScale(VectorAdapter vector) { _binding.Scale = vector; return this; }
    public readonly IDrawable SetRotation(float rotation) { _binding.Rotation = rotation; return this; }
    public readonly IDrawable SetTexture(TextureAdapter texture) { _binding.Texture = texture; ; return this; }

    public readonly object GetDrawable() => _binding;
    public readonly EColor GetBackgroundColor() => _binding.Color.ToEnum();
    public readonly EColor GetBorderColor() => _binding.Color.ToEnum();
    public readonly RectAdapter GetBounds() => _binding.GetGlobalBounds();
    public readonly VectorAdapter GetBorderSize() => (0f, 0f);
    public readonly VectorAdapter GetSize() => _binding.Texture.Size;
    public readonly VectorAdapter GetPosition() => _binding.Position;
    public readonly VectorAdapter GetScale() => _binding.Scale;
    public readonly float GetRotation() => _binding.Rotation;
    public readonly TextureAdapter GetTexture() => _binding.Texture;

    public void Dispose()
    {
        _binding.Dispose();
        _binding = null;
    }

    public static implicit operator Sprite(SpriteAdapter adapter) => (Sprite)adapter.GetDrawable();

    public static implicit operator SpriteAdapter(Sprite drawable) => new(drawable);
}
