namespace GameEngine.Adapters;

public struct FontAdapter()
{
    private Font _binding;

    public FontAdapter(object drawable) : this()
    {
        _binding = (Font)drawable ?? throw new NullReferenceException();
    }

    public readonly object GetDrawable() => _binding;

    public void Dispose()
    {
        _binding.Dispose();
        _binding = null;
    }

    public static implicit operator Font(FontAdapter adapter) => (Font)adapter.GetDrawable();

    public static implicit operator FontAdapter(Font drawable) => new(drawable);
}
