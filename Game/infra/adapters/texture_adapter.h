namespace GameEngine.Adapters;

public struct TextureAdapter()
{
    private Texture _binding;

    public TextureAdapter(object resource) : this()
    {
        _binding = (Texture)resource ?? throw new NullReferenceException();
    }

    public readonly object GetDrawable() => _binding;

    public void Dispose()
    {
        _binding.Dispose();
        _binding = null;
    }

    public static implicit operator Texture(TextureAdapter adapter) => (Texture)adapter.GetDrawable();

    public static implicit operator TextureAdapter(Texture drawable) => new(drawable);
}
