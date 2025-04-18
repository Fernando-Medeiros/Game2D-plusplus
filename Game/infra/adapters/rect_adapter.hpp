namespace GameEngine.Adapters;

/// <summary>
/// Esta classe é responsável por adaptar um rectangulo bidimensional
/// </summary>
public readonly struct RectAdapter
{
    public readonly float X;
    public readonly float Y;
    public readonly float Width;
    public readonly float Height;

    #region Constructors
    public static RectAdapter Empty => new(0, 0, 0, 0);
    public RectAdapter(RectAdapter rect) { X = rect.X; Y = rect.Y; Width = rect.Width; Height = rect.Height; }
    public RectAdapter(float x, float y, float width, float height) { X = x; Y = y; Width = width; Height = height; }
    public RectAdapter(VectorAdapter position, VectorAdapter size) { X = position.X; Y = position.Y; Width = size.X; Height = size.Y; }
    #endregion

    #region Interface
    public VectorAdapter Position() => new(X, Y);
    public VectorAdapter Size() => new(Width, Height);
    public VectorAdapter Center() => new(Width / 2, Height / 2);
    public bool Contains(VectorAdapter vector) => ((FloatRect)this).Contains(vector.X, vector.Y);
    #endregion

    #region SFML Cast Adapter
    public static implicit operator FloatRect(RectAdapter adapter) => new(adapter.X, adapter.Y, adapter.Width, adapter.Height);
    public static implicit operator IntRect(RectAdapter adapter) => new((int)adapter.X, (int)adapter.Y, (int)adapter.Width, (int)adapter.Height);
    public static implicit operator (float Left, float Top, float Width, float Height)(RectAdapter adapter) => (adapter.X, adapter.Y, adapter.Width, adapter.Height);

    public static implicit operator RectAdapter(FloatRect rect) => new(rect.Position, rect.Size);
    public static implicit operator RectAdapter(IntRect rect) => new(rect.Position, rect.Size);
    public static implicit operator RectAdapter((float Left, float Top, float Width, float Height) rect) => (rect.Left, rect.Top, rect.Width, rect.Height);
    #endregion

    #region Override
    public override string ToString() => $"({nameof(RectAdapter)} -> X:{X}, Y:{Y}, W:{Width}, H:{Height})";
    #endregion
}
