namespace GameEngine.Adapters;

/// <summary>
/// </summary>
public struct DrawableAdapter : IDisposable
{
    private object _drawable;

    #region Constructor
    public static DrawableAdapter Empty => new();
    public DrawableAdapter(Drawable graphic) => _drawable = graphic;
    public DrawableAdapter(IDrawable graphic) => _drawable = graphic;
    #endregion

    #region SFML Adapter
    public readonly object GetDrawable() => _drawable;

    public readonly Drawable GetDrawableToRender() => _drawable is Drawable ? (Drawable)_drawable : (Drawable)((IDrawable)_drawable).GetDrawable();

    public static implicit operator Text(DrawableAdapter adapter) => (Text)adapter.GetDrawable();
    public static implicit operator Sprite(DrawableAdapter adapter) => (Sprite)adapter.GetDrawable();
    public static implicit operator CircleShape(DrawableAdapter adapter) => (CircleShape)adapter.GetDrawable();
    public static implicit operator RectangleShape(DrawableAdapter adapter) => (RectangleShape)adapter.GetDrawable();

    public static implicit operator DrawableAdapter(Text drawable) => new(drawable);
    public static implicit operator DrawableAdapter(Sprite drawable) => new(drawable);
    public static implicit operator DrawableAdapter(CircleShape drawable) => new(drawable);
    public static implicit operator DrawableAdapter(RectangleShape drawable) => new(drawable);

    public static implicit operator TextAdapter(DrawableAdapter adapter) => (TextAdapter)adapter.GetDrawable();
    public static implicit operator CircleAdapter(DrawableAdapter adapter) => (CircleAdapter)adapter.GetDrawable();
    public static implicit operator SpriteAdapter(DrawableAdapter adapter) => (SpriteAdapter)adapter.GetDrawable();
    public static implicit operator RectangleAdapter(DrawableAdapter adapter) => (RectangleAdapter)adapter.GetDrawable();

    public static implicit operator DrawableAdapter(TextAdapter adapter) => new(adapter);
    public static implicit operator DrawableAdapter(CircleAdapter adapter) => new(adapter);
    public static implicit operator DrawableAdapter(SpriteAdapter adapter) => new(adapter);
    public static implicit operator DrawableAdapter(RectangleAdapter adapter) => new(adapter);
    #endregion

    public void Dispose()
    {
        ((IDrawable?)GetDrawable())?.Dispose();

        _drawable = null;

        GC.Collect(GC.GetGeneration(this), GCCollectionMode.Forced);
        GC.SuppressFinalize(this);
    }
}
